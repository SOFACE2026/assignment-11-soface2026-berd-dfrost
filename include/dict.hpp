#pragma once
#include <algorithm>
#include <vector>
#include <tuple>
#include <iterator>
#include <optional>

/**
 * @brief Container used to store assoicate keys with values.
 * values can later be retrived using the corresponding key.
 * 
 * @tparam K type of the keys stored in the dictionary.
 * @tparam V type of the values assoicated with each key.
 */
template <class K, class V>
class Dict
{
private:
    std::vector<K> key_v;
    std::vector<V> val_v;
    /*
        Helper function to find the index of a key stored in the dictionary, 
        returns -1 if not found.
    */
    int find(K key) const{
        int idx = -1;
        // Loop through keys
        for(size_t i = 0; i < key_v.size(); i++){
                // Check if key is found
                if(key == key_v[i]){
                    // Set idx
                    idx = i;
                    break;
                }
            }
        return idx;
    }

public:
    /**
     * @brief Associates the key with the specified value.
     * If the key is already in the dictionary its value is overwritten.
     * 
     * @param key key associated with the provided key.
     * @param val value assoicated with the provided key.
     */
    void set(K key, V val)
    {
        int idx = find(key);
        if(idx > -1){
            // Overwrite value if key exists
            val_v.at(idx) = val;
        }
        else{
            // Push new key and its value onto respective vectors
            val_v.push_back(val);
            key_v.push_back(key);
        }
    }

    /**
     * @brief Determines if the key is defined in the dictionary.
     * 
     * @param key key for which to look for.
     * @return true if the key is defined in the dictionary.
     * @return false otherwise.
     */
    bool has(K key) const
    {
        // Checks if key exists using find helper
        return (find(key) > -1);
    }

    /**
     * @brief Returns the number of items in the dictionary.
     * 
     * @return the number of items in the dictionary.
     */
    size_t len()
    {
        // Value and key vector should always be the same size
        assert(val_v.size() == key_v.size())
        // Returns size of value vector
        return val_v.size();
    }

    /**
     * @brief Get the value associated with the specified key.
     * If no value is found std::nullopt is returned.
     * 
     * @param key key for which to locate value.
     * @return value associated with key.
     */
    std::optional<V> get(K key) const
    {
        // Finds idx of key
        int idx = find(key);
        if(idx > -1){
            // if key is found, returns respective value
            return val_v.at(idx);
        }
        // not found, returns null
        return {std::nullopt};
    }

    /**
     * @brief Delete the specified key and its associated value
     * from the dictionary.
     * If the key is not present in the dictionary, nothing happens.
     * 
     * @param key A key currently present in the dictionary
     * which will be deleted.
     */
    void del(K key)
    {
        // finds idx of key
        int idx = find(key);
        if(idx > -1){
            // Erases key and its respective value if found
            val_v.erase(val_v.begin() + idx);
            key_v.erase(key_v.begin() + idx);
        }
    }

    /**
     * @brief List all keys of the dictionary.
     * 
     * @return vector of keys.
     */
    std::vector<K> keys()
    {
        // returns vector of keys
        return key_v;
    }

    /**
     * @brief List all values of the dictionary.
     * 
     * @return vector of values.
     */
    std::vector<V> values()
    {
        // returns vector of values
        return val_v;
    }
};