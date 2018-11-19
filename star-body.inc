% ---------------------------------------------------------------------
\title{Brain Visualization - STAR Report}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[M. Konefal \& M. Wiedhalm]
       {M. Konefał$^{1}$
        and M. Wiedhalm$^{1}$
        \\
         $^1$Group 15\\
       }

% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{27}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page
% ------------------------------------------------------------------------


\begin{document}


\maketitle

\begin{abstract}


\end{abstract}



%-------------------------------------------------------------------------
\section{Introduction}

Brain is our most important organ\cite{Murre-Sturdy95}. It is complicated nervous system which controlls most of activities in our body and play key part in human cognition. This organ could not be replaced and its function could not be artificially taken over, consequentlly any damage or serious patology change could put at risk whole organism\cite{PREIM2014541}. In the same time it is one of the least know organs inter alia because of it complicity (network consist approximately $10^{11}$ neurons and $10^{15}$ connections between of them\cite{Murre-Sturdy95}). Couple of aquisition techniques which help as to explore \textit{in vivo} this wonder of nature, but with such quantity of data it is also very important how we decide visualise it.
\\
Aquisition techniques we could devide focusing on the visualization of point-to-point brain connectivity to following categories\cite{PREIM2014541}:
\begin{itemize}
\item structural - using Diffusion MRI;
\item connectivity matrices - using EEG, MEG, fMRI, Diffusion MRIs
\end{itemize}
Especially interesting are MRI derived techniques like Diffusion MRI nad fMRI. In MRI strong magnetic field is applied over the examined structure. Basicially in these technique we mesure a time which is needed for tisuses to go back to equilibrium state after aplication of an impuls of magnetic field. To achive that we send sequence of impulses which creates MRI signal, one of them is Echo-Planar Imaging (EPI).
\\
In the Diffusion MRI we mesure indirectly movment of the water in neurons and we assume that water molecules move more often along the constrainig structures (\textit{anisotropic diffusion}), concluding from that shape of that structures. Most significant diffrenc compering mentioned technique to fMRI is that instead of water we mesure signal BOLD which indicate augmented use of glucose, which is required by active neurons. That information could help us tu identify what is the activation of diffrent parts of the brain. For fMRI we can precise two categoris: when subject is asked to do simple tack (e.g. taping with a finger) simultaneously with examination \textit{task state fMRI (tfMRI)} and when subject is in a relaxed mental state \textit{resting state fMRI (rfMRI)}.
%-------------------------------------------------------------------------
\section{Human Connectome Project}
As a one of a result of revolution noninvasive neuroimaging method in the last paragraph we are enable the analysis and visualization of human brain structure, function and connectivity in unprecedented detail\cite{Essen:2013}. In 2010, NIH Neuroscience Blueprint Institutes and Centers awarded Human Connectome Project (HCP) grants to two consortia, one led by Washington University, the University of Minnesota, and Oxford University. The aim of that ongoing project is to characterize human brain connectivity and function in a population of 1200 healthy. Acquired data should also enable comparision between brain circuit, behaviuour, and genetics at the level of individual subject.
\\
To achive that aim, particular type of data was collected:
\begin{itemize}
	\item For all 1200 subjects:
	\begin{itemize}
		\item structural MRI
		\item resting-state fMRI (rfMRI)
		\item task fMRI (tfMRI)
		\item diffusion MRI (dMRI)
	\end{itemize}
	It was done on a customized 3T scanner at Washington University, additionally 200 subject was also scanned an a 7 T scanner at the University of Minnesota.
	\item A subset of 100 subject was studied using MEG/EEG (resting-state and task-evoked) carried out at St. Louis University.
	\item Standarized behavioral tests was taken, to increase the prospects that finding based on the HCP data can in the feature be related to other large-scaled project comparing brain and behaviour.
	\item Also blood samples was acquired at the time of eachsubject's visit. Genotyping will be carried out\cite{releaseNotes}.
\end{itemize}
The project phase of acquiring data for visualization is already completed\cite{releaseNotes}.
Data are freely available to the scientific community in the raw form , but also after the multiple levels of processing needed to analyze and interpret the data. Ta achive aim of creating a database which could be use by vast community of reaserchers around the world the first phase of the project considered i. a. 3T scanning protocol and 7T scanning protocol (to acquire raw data), minimal processing pipelines, analysis approaches, informatics (one platforms for handling the data \textit{ConnectomeDB} and second for visualization and analysis \textit{Connectome Workbench}).

\begin{figure}[htb]
  \centering
  % the following command controls the width of the embedded PS file
  % (relative to the width of the current column)
  \includegraphics[width=.8\linewidth]{connectome}
  % replacing the above command with the one below will explicitly set
  % the bounding box of the PS figure to the rectangle (xl,yl),(xh,yh).
  % It will also prevent LaTeX from reading the PS file to determine
  % the bounding box (i.e., it will speed up the compilation process)
  % \includegraphics[width=.95\linewidth, bb=39 696 126 756]{sampleFig}
  %
  \parbox[t]{1.0\columnwidth}{\relax
           White matter fiber architecture from the Connectome Scanner dataset. The fibers are color-coded by direction: red = left-right, green = anterior-posterior, blue = ascending-descending (RGB=XYZ)\cite{eHCP}.
           }
  %
  \caption{\label{fig:connectome}
           One of the pictures from the gallery of Human Connectome Project.}
\end{figure}

\subsection{Aspects of the Preprocessing Pipeline}
In that sections we focus on major improvments which was done in the framework of the project. Main advences was made for data comming from dMRI\cite{Sotiropoulos:2013}.
\\
Tractography algorithms was used for structural connectivity analysis, which can succesfully localise fibre bundles within white matter and therefore allows the study of specific brain pathways. This approach have some limitation, we will try to give short overview resarches in the HCP overcome this limitations.

\subsubsection{Image Reconstruction}
Images are obtained from reconstuction combining information from different receivers. It could strongly affected fibre orientation estimation and subsequently bias tractography results, because of Rician properties and noise. This effects increase with the number of receiver channels. To reduce effect of the noise (especially noise flor), channels was minimized using a sensitivity encoding (SENSE). It combines data from all channels into a single complex image, whose magnitude is subsequently computed. It therefore preserves the Rician properties and increases the dynamic range of the signal.
\subsubsection{Distortion Correction}
EPI images (created from EPI signals) are plagued by distortions caused by sensitivity to inhomogeneities of the magnetic field. It could be coused by diffrent factors, like by object itself, or by fast switching of the diffusion gradients (gradinets in MRI are used to locatize in space part of the subject which is currently analyzed by scanner). It was developed a model-based approach that simultaneously considers and corrects for all types of distortions. The distortion correction is based on the idea of manipulating the acquisitions so that a given field inhomogeneity manifests itself differently in different images. Inversion of this model enables accurate estimation of the corrected data.
\subsubsection{Fibre Orientation Estimation}
Several methods have been proposed for inferring the fibre orientation density function (fODF) from diffusion MRI, targeting either the fODF directly or approximations of it. The underlying idea for the former group of methods is that the measured signal \textbf{S} can be considered as the spherical convolution of the fODF \textbf{F} and an impulse response function \textbf{R}. Then to estimate \textbf{F} we deal with deconvolution function.
\\\
The ball \& stick model is powerful parametric deconvolution method, but it is not appropriate for multi-shell datasets. It developed a parametric deconvolution extension of the ball \& stick model, which is suitable for that purpose. It was modified the single-fibre kernel \textbf{R} to represent the signal arising from a distribution of diffusivities within a voxel, rather than a single diffusivity. Using a Gamma distribution of diffusivities allows an analytic parametric expression to be obtained.
Thanks to this model crossing-fibre sensitivity between single and multi-shell parametric spherical deconvolution was increased.
\subsubsection{Tractography}

%-------------------------------------------------------------------------
\section{Responsibilities}

Marcin Konefał worked on:
\begin{itemize}
\item Preperation of latex file
\item Section - Introduction
\item Section - Human Connectome Project
\end{itemize}

%-------------------------------------------------------------------------
\bibliography{egbibsample}
\bibliographystyle{eg-alpha}
%\bibliographystyle{eg-alpha-doi}

\end{document}
