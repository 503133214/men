class Cinema:
    def __init__(self, cinema_id, cinema_name):
        self.__cinema_id = cinema_id
        self.__cinema_name = cinema_name
        self.__showing_now = []
        self.__coming_soon = []
        self.__shown = []

    # Methods to update attributes
    def add_movie_to_coming_soon(self, movie):
        self.__coming_soon.append(movie)

    def add_movie_to_showing_now(self, movie):
        if movie in self.__coming_soon:
            self.__coming_soon.remove(movie)
            self.__showing_now.append(movie)

    def remove_movie_from_showing_now(self, movie):
        if movie in self.__showing_now:
            self.__showing_now.remove(movie)
            self.__shown.append(movie)

    # Methods to display attributes
    def display_coming_soon(self):
        return self.__coming_soon

    def display_showing_now(self):
        return self.__showing_now

    def display_shown(self):
        return self.__shown

    # Utility methods for external interaction
    def get_cinema_id(self):
        return self.__cinema_id

    def get_cinema_name(self):
        return self.__cinema_name

# Main program to interact with the Cinema class
def main_menu():
    cinema = Cinema(1, "Grand Cinema")

    while True:
        print("\nCinema Management System")
        print("1. Add new movie to Coming Soon")
        print("2. Add new movie to Showing Now")
        print("3. Remove a movie from Showing Now")
        print("4. Print Coming Soon list")
        print("5. Print Showing Now list")
        print("6. Print Shown list")
        print("7. Exit")
        choice = input("Select an option: ")

        if choice == '1':
            movie = input("Enter the name of the movie to add to Coming Soon: ")
            cinema.add_movie_to_coming_soon(movie)
            print(f"{movie} added to Coming Soon.")
        elif choice == '2':
            movie = input("Enter the name of the movie to add to Showing Now: ")
            cinema.add_movie_to_showing_now(movie)
            print(f"{movie} added to Showing Now.")
        elif choice == '3':
            movie = input("Enter the name of the movie to remove from Showing Now: ")
            cinema.remove_movie_from_showing_now(movie)
            print(f"{movie} removed from Showing Now.")
        elif choice == '4':
            print("Coming Soon list:")
            for movie in cinema.display_coming_soon():
                print(movie)
        elif choice == '5':
            print("Showing Now list:")
            for movie in cinema.display_showing_now():
                print(movie)
        elif choice == '6':
            print("Shown list:")
            for movie in cinema.display_shown():
                print(movie)
        elif choice == '7':
            with open('output.txt', 'w') as file:
                file.write("Coming Soon:\n")
                file.writelines(movie + "\n" for movie in cinema.display_coming_soon())
                file.write("\nShowing Now:\n")
                file.writelines(movie + "\n" for movie in cinema.display_showing_now())
                file.write("\nShown:\n")
                file.writelines(movie + "\n" for movie in cinema.display_shown())