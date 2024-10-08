# ArduCar

The project is a remote controlled mini car.
- Car (receiver)
    - Arduino Uno board
    - 2 L298N Dual H-Bridge
    - 4 motors and 4 wheels
    - HM10 Bluetooth module (slave)
- Controller (main)
    - Arduino Uno board
    - 4 tilt sensors
    - HM10 Bluetooth module (master)

The controller is a handle with a square platform, where on each edge there is a tilt sensor pointing outwards and slightly down. This ensures that when the controller is at rest, the sensors pick up no tilt, and when there is a tilt, the one on the opposite end will be active. This way, the controller can register all 4 tilting motion (forward, backward, left, right). Each time the controller changes its state, it will send a message via the Bluetooth serial port.

The car has two H-bridge so that it can turn in place and go forward/backward. For example, when turning left, the left wheels will turn backward, and the right wheels will turn forward. It receives a message from the controller via its Bluetooth serial port, and moves accordingly.

There are better ways for communication between two Arduino board, but we used two HM10 Bluetooth module to communicate with each other because that was the available hardware our teacher had and we didn't want to spend money buying parts.
