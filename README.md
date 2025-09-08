# first-repository
Serialization Lab — README
What I Did

I made a class with Person as the base, and Student and Instructor as subclasses.
They can output themselves in JSON, YAML, and CSV formats.

I also added some extras:

A function to write a single CSV for any set of people .

from_json methods for Student and Instructor so you can go object to JSON to object and check it works.

Exceptions

I throw ValidationError in a few places:

If id is ≤ 0

If name or office is empty

If email is invalid

If grad_year is too small
I also added SerializationError in case something goes wrong if saving.

CSV Escaping

CSV cells get wrapped in quotes if they have commas, quotes, or newlines.
SO the quotes inside the text would be doubled like "Adam, ""The Best""".

Build & Test

Branch: lab/inheritance-serialization

Build: mkdir build && cd build && cmake -S .. -B . -DCMAKE_BUILD_TYPE=Debug && cmake --build .

Run tests: ctest --output-on-failure

Run demo: ./app