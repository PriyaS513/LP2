flights=[
    {
        'flight_no':'flight1',
        'source':'source1',
        'destination':'destination2',
        'start_time':'10:00',
        'arrival_time':'11:00'
    },
    {
        'flight_no': 'flight2',
        'source': 'source2',
        'destination': 'destination1',
        'start_time': '11:00',
        'arrival_time': '12:00'
    },
    {
        'flight_no': 'flight3',
        'source': 'source2',
        'destination': 'destination3',
        'start_time': '12:00',
        'arrival_time': '1:00'
    },
]
air_cargo=[
    {
        'cargo_no':'cargo1',
        'source':'source1',
        'destination':'destination2',
        'start_time':'11:00'
    },
    {
        'cargo_no': 'cargo2',
        'source': 'source2',
        'destination': 'destination2',
        'start_time': '1:00'
    },
    {
        'cargo_no': 'cargo3',
        'source': 'source3',
        'destination': 'destination1',
        'start_time': '11:00'
    },
]

def get_flight(source,destination):
    schedule=[]
    for flight in flights:
        if flight['source']==source and flight['destination']==destination:
            schedule.append(flight)
    return schedule

def get_cargo(source,destination):
    schedule=[]
    for cargo in air_cargo:
        if cargo['source']==source and cargo['destination']==destination:
            schedule.append(cargo)
    return schedule

source=str(input("Enter the source : "))
destination=str(input("Enter the destination : "))

flight=get_flight(source,destination)
cargo=get_cargo(source,destination)

print("Flight")
for schedule in flight:
    print(schedule)

print("\nCargo")
for schedule in cargo:
    print(schedule)