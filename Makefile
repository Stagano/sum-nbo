CXX= g++
TARGET= sum-nbo
SRC = sum-nbo.cpp

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
