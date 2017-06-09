/*
 * customPDE.h
 *
 *  Created on: Feb 24, 2017
 *      Author: stephendewitt
 */

#ifndef APPLICATIONS_ALLENCAHN_CUSTOMPDE_H_
#define APPLICATIONS_ALLENCAHN_CUSTOMPDE_H_

#include "../../include/matrixFreePDE.h"

template <int dim, int degree>
class customPDE: public MatrixFreePDE<dim,degree>
{
public:
	customPDE(userInputParameters<dim> _userInputs): MatrixFreePDE<dim,degree>(_userInputs) {};

private:

	#include "../../include/typeDefs.h"

	void residualRHS(const std::vector<modelVariable<dim> > & modelVarList,
			  	  	 std::vector<modelResidual<dim> > & modelResidualsList,
					 dealii::Point<dim, dealii::VectorizedArray<double> > q_point_loc) const;

	void residualLHS(const std::vector<modelVariable<dim> > & modelVarList,
	  		  	  	 modelResidual<dim> & modelRes,
					 dealii::Point<dim, dealii::VectorizedArray<double> > q_point_loc) const;

	void energyDensity(const std::vector<modelVariable<dim> > & modelVarList, const dealii::VectorizedArray<double> & JxW_value,
			  	  	 dealii::Point<dim, dealii::VectorizedArray<double> > q_point_loc);

	// Nicknames for user-defined variables are defined here for now. Maybe include this from a separate file?
	double MnV = boost::get<double>(this->userInputs.model_constants[0]);
	double KnV = boost::get<double>(this->userInputs.model_constants[1]);
};



#endif /* APPLICATIONS_ALLENCAHN_CUSTOMPDE_H_ */
