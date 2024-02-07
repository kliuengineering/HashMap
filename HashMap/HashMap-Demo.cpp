#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

template <typename keyType, typename valueType>
class HashMap 
{
public:
    HashMap();
    ~HashMap();
    
    void Insert(const keyType& key, const valueType& value);
    valueType GetValue(const keyType& key);
    void Remove(const keyType& key);
    void GetAllValue();
    
private:
    int numBuckets;
    vector< vector< pair <keyType, valueType> > > buckets;
};


// Constructor
template <typename keyType, typename valueType>
HashMap<keyType, valueType>::HashMap() 
{
    numBuckets = 16;
    buckets.resize(numBuckets);
}


// Destructor
template <typename keyType, typename valueType>
HashMap<keyType, valueType>:: ~HashMap() 
{
    for (auto& bucket : buckets) 
    {
        bucket.clear();
    }
}


// Insert
template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Insert(const keyType& key, const valueType& value) 
{
    int hashIndex = hash<keyType>{}(key) % numBuckets; // Compute hash index
    for (auto& pair : buckets[hashIndex]) 
    {
        if (pair.first == key) 
        { // If pair already exists, update to new value
            pair.second = value;
            return;
        }
    }
    buckets[hashIndex].push_back(make_pair(key, value)); // Otherwise, insert the pair into the hash map
}


// GetValue
template <typename keyType, typename valueType>
valueType HashMap<keyType, valueType>::GetValue(const keyType& key) 
{
    keyType temp = keyType{};
    
    int hashIndex = hash<keyType>{}(key) % numBuckets; // Compute hash index
    for (auto& pair : buckets[hashIndex]) 
    {
        if (pair.first == key) 
        { // If key is found, return corresponding value
            return pair.second;
        }
        else 
        {
            return valueType(); // If key is not found, return default constructor
        }
    }
    
    return temp;
}


// Remove
template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Remove(const keyType& key) 
{
    int hashIndex = hash<keyType>{}(key) % numBuckets;
    for (auto it = buckets[hashIndex].begin(); it != buckets[hashIndex].end(); ++it) 
    {
        if (it->first == key) 
        {
            buckets[hashIndex].erase(it); // If pair is found, erase it
            return;
        }
    }
}


// get all
template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::GetAllValue() 
{
    
   //Iterate through the buckets hashindex to display all key,value pair
    cout << "iterate through the buckets hashindex to display all key, value pair" << endl;
    
    for (const auto& bucket : buckets)
    {
        // Iterate through each pair in the bucket
        for (const auto& pair : bucket)
        {
            // Print the key-value pair
            cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
        }
    }
}


int main()
{
//Declare a Hash Map
// 
//     1. Add code here to declare
// 
    HashMap<string, string> my_hashmap;
    
    cout << "  Add code here to declare" << endl;
    //Add the following pairs

    vector<string> keys;
    vector<string> values;
    
    keys.push_back("AB");
    keys.push_back("BC");
    keys.push_back("ON");
    keys.push_back("MB");
    keys.push_back("SK");
    
    values.push_back("Calgary");
    values.push_back("Vancouver");
    values.push_back("Scarborough");
    values.push_back("Winnipeg");
    values.push_back("Saskatoon");

    //     2. Add code here to to call function add
    cout << "   Add the code to add following pairs" << endl;

//"AB"->"Calgary"
//"BC"->"Vancouver";
//"ON"-> "Scarborough";
//"MB"->"Winnipeg";
  
    for(int i=0; i<5; i++)
    {
        my_hashmap.Insert(keys[i], values[i]);
    }
    
    
    puts("");
    for(int i=0; i<5; i++)
    {
        cout << "Value of " << keys[i] << ": " << my_hashmap.GetValue(keys[i]) << endl;
    }
    puts("");

    
    puts("");
    my_hashmap.GetAllValue();
    puts("");
    
    
    return 0;

}
