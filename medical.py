
class Rule:
    def __init__(self, symptoms, disease):
        self.symptoms = symptoms
        self.disease = disease


class ExpertSystem:
    def __init__(self):
        self.rules = []
        self.symptoms = set()
        self.diseases = set()

    def add_rule(self, symptoms, disease):


        rule = Rule(symptoms, disease)
        self.rules.append(rule)
        self.symptoms.update(symptoms)
        self.diseases.add(disease)

    def diagnose(self, user_symptoms):
        possible_diseases = set()  # Initialize an empty set for possible diseases

        for rule in self.rules:
            if set(rule.symptoms).issubset(user_symptoms):
                possible_diseases.add(rule.disease)  # Add the disease to possible_diseases

        if len(possible_diseases) == 0:
            print("Sorry, we couldn't identify the disease based on the symptoms provided.")
        elif len(possible_diseases) == 1:
            disease = possible_diseases.pop()
            print("Based on the symptoms provided, it is likely that you have", disease)
        else:
            print("Based on the symptoms provided, it could be one of the following diseases:")
            for disease in possible_diseases:
                print("-", disease)



# Create an instance of the ExpertSystem
expert_system = ExpertSystem()

# Add rules to the expert system

expert_system.add_rule(["fever", "cough"], "Common Cold")
expert_system.add_rule(["fever", "fatigue", "headache"], "Flu")
expert_system.add_rule(["rash", "itching"], "Allergy")
expert_system.add_rule(["abdominal pain", "nausea"], "Food Poisoning")
expert_system.add_rule(["chest pain", "shortness of breath"], "Heart Disease")

# Get user input for symptoms
user_input = input("Enter your symptoms (comma-separated): ")
user_symptoms = [symptom.strip() for symptom in user_input.split(",")]

# Perform diagnosis
expert_system.diagnose(user_symptoms)