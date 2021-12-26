#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <vector>
#include <sstream> 

template <class T>

class ComboBoxContainer : public Gtk::ComboBoxText {
	public:
		ComboBoxContainer(T container){ 	
			for(auto c : container){ 
				oss.str(""); 
				oss <<  *c; 
				append(oss.str());
			}
        
      }
  
	private:
		 std::ostringstream oss;
		 std::vector<T> container;
		 
};			

#endif