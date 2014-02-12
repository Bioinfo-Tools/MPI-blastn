MPI-blastn
==========

A high performance parallel version of nucleotide BLAST+ for sequence search

#Software Requirements

Any version of MPI (Message Passing Interface) library, either OpenMPI or Intel MPI.
OpenMPI is free/open source MPI library and is available at http://www.open-mpi.org

#Download

On Linux:

    wget https://github.com/Bioinfo-Tools/MPI-blastn/archive/master.zip -O MPI-blastn.zip 
    unzip MPI-blastn.zip

On Mac OSX:

    curl -L https://github.com/Bioinfo-Tools/MPI-blastn/archive/master.zip -o MPI-blastn.zip
    unzip MPI-blastn.zip

#Install

This step requires the mpicc compiler from any MPI library version (OpenMPI, IntelMPI, etc.). OpenMPI is free/open source MPI library and is available at http://www.open-mpi.org.
If you are in a cluster or HPC environment, this library may be already installed and you just need to load the module, like in the following example (this command may vary depending on which HPC environment you are using):

    module load gcc
    module load openmpi

Than you are ready to install:

    cd MPI-blastn-master
    sh install.sh

#Run

After install, MPI-blast can be executed from the Release directory:
 
    mpirun -np <NUM_NODES> ./mpiblastn <INPUT_QUERY> <INPUT_DB> <OUTPUT_TXT> <NUM_CORES>

    where:
    NUM_NODES is the number of computing nodes    
    INPUT_QUERY is the name of the input query sequence file in fasta format (http://en.wikipedia.org/wiki/FASTA_format)
    INPUT_DB is the name of the input database in BLAST database format (http://selab.janelia.org/people/farrarm/blastdbfmtv4/blastdbfmt.html)
    OUTPUT_TXT is the name of the output file (text in tabular format)
    NUM_CORES is the number of cores per node to be used

#Examples

The input files listed bellow are available in the examples directory of this software package.

    mpirun -np 8 ./mpiblastn Entrada30.fasta NCBI-ntnr_18S_all output.txt 24

In this example above we are running MPI-blastn for the input query sequences in Entrada30.fasta file against the NCBI-ntnr_18S_all database, using 8 nodes and 24 cores/processors per node.

The final result generated in the ouput.txt file is a text file in tabular format, as follows:

    Query	Subject	Identity(%)	Matches		Gaps	Start	End	E-value	Bitscore
    Seq_1	gi|1708|emb|X00640.1|Rabbit_18S_ribosomal_RNA_sequence	100.00	1858	0	1	1858	0.0	3333
    Seq_2	gi|2485|emb|X58052.1|D.bruxellensis_gene_for_18S_ribosomal_RNA	100.00	1799	0	1	1799	0.0	3245
    Seq_3	gi|2588|emb|X58571.1|C.immitus_DNA_for_18S_ribosomal_RNA,_partial	100.00	1713	0	1	1713	0.0	3090
    Seq_4	gi|2686|emb|X58053.1|D.hansenii_gene_for_18S_ribosomal_RNA	100.00	1800	0	1	1800	0.0	3247
