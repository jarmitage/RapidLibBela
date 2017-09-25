#ifndef regression_h
#define regression_h

#include <vector>
#include "modelSet.h"

/*! Class for implementing a set of regression models.
 *
 * This doesn't do anything modelSet can't do. But, it's simpler and more like wekinator.
 */

class regression : public modelSet {
public:
    /** with no arguments, just make an empty vector */
    regression();
    /** create based on training set inputs and outputs */
    regression(const std::vector<trainingExample<double> > &trainingSet);
    /** create with proper models, but not trained */
    regression(const int &numInputs, const int &numOutputs);
    
    /** destructor */
    ~regression() {};
    
    /** Train on a specified set, causes creation if not created */
    bool train(const std::vector<trainingExample<double> > &trainingSet);
    
    /** Call before train, to set the number of training epochs */
    void setNumEpochs(const int &epochs);
    
    /** Check how many hidden layers are in each model. This feature is temporary, and will be replaced by a different design. */
    std::vector<int> getNumHiddenLayers();
    
    /** Set how many hidden layers are in all models. This feature is temporary, and will be replaced by a different design. */
    void setNumHiddenLayers(const int &num_hidden_layers);
    
private:
    int numHiddenLayers; //Temporary -- this should be part of the nn class. -mz
    int numEpochs; //Temporary -- also should be part of nn only. -mz
};

#endif
