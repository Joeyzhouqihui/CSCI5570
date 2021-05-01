import os
import random
import sys

origin = "../inputs/{0}_csr"
gorder = "../inputs/{0}_csr_gorder"
hubsort = "../inputs/{0}_csr_hubsort"
hubcluster = "../inputs/{0}_csr_hubcluster"

origin_cost = 0
gorder_cost = 0
hubsort_cost = 0
hubcluster_cost = 0

command = "./../ligra/apps/BFS -r {0} {1}"

def getcost(result_str):
  temp = 0
  for line in result_str.split('\n'):
    if len(line.split()) > 0:
      temp += float(line.split()[-1])
  temp = temp / 3
  return temp

def run(filename, seeds):
  tmp = 0
  count = 0
  for seed in seeds:
    result_str = os.popen(command.format(seed, filename)).read()
    tmp += getcost(result_str)
    count += 1
  return tmp / count

def getsources(num):
  sources = []
  for i in range(0, num):
    sources.append(random.randint(0, 13000000))
  return sources

if __name__ == "__main__":
  if len(sys.argv) < 3:
    print("need to set graph dataset and number of sources in argv")
  else:
    graph_name = sys.argv[1]
    source_num = sys.argv[2]
    
    sources = getsources(source_num)
    cost = run(origin.format(graph_name), sources)
    print("origin: ", cost)

    sources = getsources(source_num)
    gorder_cost = run(gorder.format(graph_name), sources)
    print("gorder: ", gorder_cost)

    sources = getsources(source_num)
    hubsort_cost = run(hubsort.format(graph_name), sources)
    print("hubsort: ", hubsort_cost)

    sources = getsources(source_num)
    hubcluster_cost = run(hubcluster.format(graph_name), sources)
    print("hubcluster: ", hubcluster_cost)

