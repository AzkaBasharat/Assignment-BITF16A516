class Process:
    def __init__(self, p_no, arrival_time, burst_time):
        self.p_no = p_no
        self.arrival_time = arrival_time
        self.burst_time = burst_time

    def __str__(self):
        return self.p_no + " " + self.arrival_time + " " + self.burst_time


process_list = []
file = open("fcfs.txt", "r")
for line in file:
    num = line.split(' ')
    process = Process(num[0], num[1], num[2])
    process_list.append(process)

total_time=0

for i in len(process_list):
    total_time=total_time+i.burst_time

print ("P_No\t"+"Time")

for num in total_time:
    sorted_process = sorted(process_list, key=lambda x: (x.arrival_time,x.burst_time))
    time=0
    for process in sorted_process:
        time += int(process.burst_time)
        print(process.p_no + "\t" + str(time))
        process.burst_time-1
