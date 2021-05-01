import os
import random

origin = "inputs/unweighted/wikipedia_csr"
gorder = "inputs/unweighted/pokec_csr_gorder"
hubsort = "inputs/unweighted/pokec_csr_hubsort"
hubcluster = "inputs/unweighted/pokec_csr_hubcluster"

origin_cost = 0
gorder_cost = 0
hubsort_cost = 0
hubcluster_cost = 0

command = "./ligra/apps/BFS -r {0} {1}"

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

sources = getsources(10)
cost = run(origin, sources)
print("cost: ", cost)

#sources = getsources(100)
#gorder_cost = run(gorder, sources)
#print("gorder: ", gorder_cost)

#sources = getsources(100)
#hubsort_cost = run(hubsort, sources)
#print("hubsort: ", hubsort_cost)

#sources = getsources(100)
#hubcluster_cost = run(hubcluster, sources)
#print("hubcluster: ", hubcluster_cost)

