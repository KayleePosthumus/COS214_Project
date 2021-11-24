#include "LaunchStation.h"

LaunchStation *LaunchStation::_launchStation = 0;

LaunchStation::LaunchStation()//this is the contructor for the LaunchStation
{
}

LaunchStation::~LaunchStation()//this is the destrucotr for LaunchStation. Is clears the memory
{
	while (!_simulations.empty()) {
		if (_simulations.back())
		{
			delete _simulations.back();
		}

		_simulations.pop_back();//this pops the back
	}

	delete _launchStation;//this deletes
}

LaunchStation* LaunchStation::instance()//this a fuction that creates an instance
{
	if (!_launchStation)
		_launchStation = new LaunchStation();//this creates object

	return _launchStation;//this returns
}

void LaunchStation::setSatelliteList(StarlinkSatellite* satelliteList)//this is a fuction that sets the satelliteList
{
	_satelliteList = satelliteList;
}

void LaunchStation::AddSimulation()//this fuction adds a simulation
{
	cout << "\nPlease select the type of rocket:\n1.Falcon 9\n2.Falcon Heavy" << endl;

	int rocketType;
	cin >> rocketType;

	if(rocketType == 1)
	{
		rocket = 1;
		RocketBuilder* builder = new Falcon9Builder();
		builder->ConstructRocket();
		builder->AddCoresAndMerlinEngines();
		builder->AddVacuumMerlinEngines();

		cout << "\nPlease select a payload:\n1.Dragon Spacecraft\n2.Crew Dragon\n3.Starlink Satellites" << endl;

		int payloadType;
		cin >> payloadType;

		if(payloadType == 1)
		{
			builder->AddPayload(dragon, 1);
		}
		else if(payloadType == 2)
		{
			builder->AddPayload(crewDragon, 1);
		}
		else if(payloadType == 3)
		{
			cout << "\nPlease input the number of satellites:" << endl;

			int numSatellites;
			cin >> numSatellites;

			while(numSatellites <= 0 || numSatellites > 60)
			{
				cout << "\nA minimum of 1 and maximum of 60 satellites is allowed" << endl;
				cout << "Please input the number of satellites:" << endl;
				cin >> numSatellites;
			}

			builder->AddPayload(satellites, numSatellites);
		}

		_simulations.push_back(builder->GetRocket());

		//Delete memory
		delete builder;
	}
	else if(rocketType == 2)
	{
		rocket = 2;
		RocketBuilder* builder = new FalconHeavyBuilder();
		builder->ConstructRocket();
		builder->AddCoresAndMerlinEngines();
		builder->AddVacuumMerlinEngines();

		cout << "\nPlease select a payload:\n1.Dragon Spacecraft\n2.Crew Dragon" << endl;

		int payloadType;
		cin >> payloadType;

		if(payloadType == 1)
		{
			builder->AddPayload(dragon, 1);
		}
		else if(payloadType == 2)
		{
			builder->AddPayload(crewDragon, 1);
		}

		_simulations.push_back(builder->GetRocket());

		//Delete memory
		delete builder;
	}
}

void LaunchStation::EditSimulation(int type)
{
	if(type == 1)
	{
		RocketBuilder* builder = new Falcon9Builder();
		builder->ConstructRocket();
		builder->AddCoresAndMerlinEngines();
		builder->AddVacuumMerlinEngines();

		cout << "\nPlease select a payload:\n1.Dragon Spacecraft\n2.Crew Dragon\n3.Starlink Satellites" << endl;

		int payloadType;
		cin >> payloadType;

		if(payloadType == 1)
		{
			builder->AddPayload(dragon, 1);
		}
		else if(payloadType == 2)
		{
			builder->AddPayload(crewDragon, 1);
		}
		else if(payloadType == 3)
		{
			cout << "\nPlease input the number of satellites:" << endl;

			int numSatellites;
			cin >> numSatellites;

			while(numSatellites <= 0 || numSatellites > 60)
			{
				cout << "\nA minimum of 1 and maximum of 60 satellites is allowed" << endl;
				cout << "Please input the number of satellites:" << endl;
				cin >> numSatellites;
			}

			builder->AddPayload(satellites, numSatellites);
		}

		_simulations.push_back(builder->GetRocket());

		//Delete memory
		delete builder;
	}
	else if(type == 2)
	{
		RocketBuilder* builder = new FalconHeavyBuilder();
		builder->ConstructRocket();
		builder->AddCoresAndMerlinEngines();
		builder->AddVacuumMerlinEngines();

		cout << "\nPlease select a payload:\n1.Dragon Spacecraft\n2.Crew Dragon" << endl;

		int payloadType;
		cin >> payloadType;

		if(payloadType == 1)
		{
			builder->AddPayload(dragon, 1);
		}
		else if(payloadType == 2)
		{
			builder->AddPayload(crewDragon, 1);
		}

		_simulations.push_back(builder->GetRocket());

		//Delete memory
		delete builder;
	}
}

void LaunchStation::DragonStage2(Payload* d)
{
	cout << "\nThe " << d->GetName() << " successfully docked at the International Space Station" << endl;
	cout << "\nCargo on board: " << endl;
	cout << d->GetCargo();
}

void LaunchStation::CrewDragonStage2(Payload* d)
{
	cout << "\nThe " << d->GetName() << " successfully docked at the International Space Station" << endl;
	cout << "\nCargo on board: " << endl;
	cout << d->GetCargo();
	cout << "\nPassengers on board: " << endl;
	cout << d->GetPassengers();
}

void LaunchStation::SatellitesStage2(Payload* d)
{
	cout << "\nThe Starlink Satellites successfully entered a Low Earth Orbit" << endl;
	Laser* laser = new Laser(d);
	laser->notify();

	d->CommunicateGround();

	delete laser;
}

void LaunchStation::TestSimulation()
{
	cout << "\nWould you like to edit the simulation or proceed to launch?\n1.Edit Simulation\n2.Proceed to Launch" << endl;
	int edit;
	cin >> edit;

	if(edit == 1)
	{
		_simulations.pop_back();
		cout << "\nSelect what you would like to edit\n1.Rocket\n2.Payload" << endl;
		int part;
		cin >> part;

		if(part == 1)
		{
			AddSimulation();
		}
		else
		{
			EditSimulation(rocket);
		}

		TestSimulation();
	}
	else
	{
		caretaker = new RocketCaretaker();
		caretaker->setMemento(_simulations[0]->createMemento());

		cout << "\nSimulation 1:" << endl;
		_simulations[0]->PrintDetails();

		cout << "\nEnter 0 to launch the simulation:" << endl;
		int launch;
		cin >> launch;

		launchButtons = new Button(new TakeOff(_simulations[0]));
		_observer = new Observer(_simulations[0]);

		_simulations[0]->attach(_observer);

		cout << "\nSimulation 1:" << endl << endl;
		launchButtons->TakeOff();

		if(_observer->GetObserverState())
		{
			_simulations[0]->SetStage(new Stage2());
			_simulations[0]->PrintStage();

			if(_simulations[0]->GetPayloadName() == "Dragon Spacecraft\n")
			{
				DragonStage2(_simulations[0]->GetPayload());
			}
			else if(_simulations[0]->GetPayloadName() == "Crew Dragon\n")
			{
				CrewDragonStage2(_simulations[0]->GetPayload());
			}
			else
			{
				SatellitesStage2(_simulations[0]->GetPayload());
			}
		}
		else
		{
			cout << "\nThe rocket sustained too much damaged and did not make it to the next stage." << endl;
		}

		_simulations[0]->PrintDetails();

		_simulations[0]->detach(_observer);

		delete launchButtons;
		delete _observer;
	}
}

void LaunchStation::RunSimulations()
{
	cout << "WELCOME TO THE SPACEX SIMULATIONS" << endl;
    cout << "_________________________________" << endl << endl;

    cout << "Please choose the type of simulation to run:\n1.Test\n2.Actual\n0.Exit" << endl;

	int simType;
	cin >> simType;

	while(simType != 0)
	{
		if(simType == 1)
		{
			cout << "TEST SIMULATION" << endl;

			AddSimulation();
			TestSimulation();
			_simulations[0]->PrintDetails();

			cout << "\nWould you like to run the simualtion again:\n1.Yes\n2.No" << endl;
			int again;
			cin >> again;
			while(again == 1)
			{
				_simulations[0]->restoreMemento(caretaker->getMemento());
				cout << "\nRockets have been reset" << endl;
				delete caretaker;
				caretaker = nullptr;
				_simulations[0]->PrintDetails();
				TestSimulation();

				cout << "\nWould you like to run the simualtion again:\n1.Yes\n2.No" << endl;
				cin >> again;
			}

			_simulations[0]->PrintDetails();

			if(caretaker)
				delete caretaker;

			simType = 0;
		}
		else if(simType == 2)
		{
			cout << "\nACTUAL SIMULATION" << endl;

			int addSimulations = 1;
			while(addSimulations == 1)
			{
				AddSimulation();
				cout << "\nWould you like to add more simulations or proceed to launch?\n1.Add simulations\n2.Proceed to Launch" << endl;
				cin >> addSimulations;
			}

			cout << "\nCurrent Simulations:" << endl;
			for(size_t i = 0; i < _simulations.size(); ++i)
			{
				cout << "\nSimualtion " << i+1 << ":" << endl;
				_simulations[i]->PrintDetails();
			}

			for(size_t i = 0; i < _simulations.size(); ++i)
			{
				RocketCaretaker* caretaker = new RocketCaretaker();
				caretaker->setMemento(_simulations[i]->createMemento());

				cout << "\nStatic Fire " << i+1 << ":" << endl;
				_simulations[i]->TakeLiftOffDamage();

				_simulations[i]->restoreMemento(caretaker->getMemento());
				cout << "Rocket refurbished" << endl;

				delete caretaker;
			}

			cout << "\nEnter 0 to launch all simulations:" << endl;
			int launch;
			cin >> launch;

			for(size_t i = 0; i < _simulations.size(); ++i)
			{
				launchButtons = new Button(new TakeOff(_simulations[i]));
				_observer = new Observer(_simulations[i]);

				_simulations[i]->attach(_observer);

				cout << "\nSimualtion " << i+1 << ":" << endl << endl;
				launchButtons->TakeOff();

				if(_observer->GetObserverState())
				{
					_simulations[i]->SetStage(new Stage2());
					_simulations[i]->PrintStage();

					if(_simulations[i]->GetPayloadName() == "Dragon Spacecraft\n")
					{
						DragonStage2(_simulations[i]->GetPayload());
					}
					else if(_simulations[i]->GetPayloadName() == "Crew Dragon\n")
					{
						CrewDragonStage2(_simulations[i]->GetPayload());
					}
					else
					{
						SatellitesStage2(_simulations[i]->GetPayload());
					}
				}
				else
				{
					cout << "\nThe rocket sustained too much damaged and did not make it to the next stage." << endl;
				}

				_simulations[i]->PrintDetails();
				_simulations[i]->detach(_observer);

				delete launchButtons;
				delete _observer;
			}

			while(!_simulations.empty())
				_simulations.pop_back();

			cout << "\nPlease choose the type of simulation to run:\n1.Test\n2.Actual\n0.Exit" << endl;
			cin >> simType;
		}
		else
		{
			cout << "Illegal Input" << endl;
			cout << "\nPlease choose the type of simulation to run:\n1.Test\n2.Actual\n0.Exit" << endl;
			cin >> simType;
		}
	}

	cout << "\nSIMULATIONS ENDED" << endl;
	cout << "__________________" << endl;
}