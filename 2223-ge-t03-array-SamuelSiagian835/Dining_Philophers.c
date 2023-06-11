
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>  		//Header file yang digunakan dalam program.
#include<semaphore.h>
#include<unistd.h>

sem_t room;					//Deklarasi dua buah semafor, room dan chopstick.
sem_t chopstick[5];

void * philosopher(void *);
void eat(int);				//Deklarasi fungsi philosopher() dan eat().

int main()					//main() function, menjalankan program dengan melakukan inisialisasi semafor, 
							//membuat thread philosopher, dan menunggu thread selesai dijalankan.
{
	printf("Dining Philophers dengan Semaphor 		:");		//perintah untuk mencetak string "Dining Philophers dengan Semaphor :"
	int i,a[5];				//deklarasi variabel i dan array a yang memiliki 5 elemen
	pthread_t tid[5];		//deklarasi array tid yang memiliki 5 elemen bertipe data pthread_t, yang akan digunakan untuk menyimpan ID thread
	
	sem_init(&room,0,4);	//perintah untuk menginisialisasi semaphore dengan nama "room" yang memiliki nilai awal 4. Semaphore "room" 
							//akan digunakan untuk membatasi jumlah philosopher yang dapat duduk di meja sekaligus, yaitu sebanyak 4.
	
	for(i=0;i<5;i++)		//kode ini menginisialisasi lima semaphore
		sem_init(&chopstick[i],0,1);		//
		
	for(i=0;i<5;i++){		//kode ini menginisialisasi lima semaphore
		a[i]=i;				//menginisialisasi a indeks i
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);		//fungsi yang digunakan untuk membuat thread baru dan memiliki empat parameter//
	}
	for(i=0;i<5;i++)		//kode ini menginisialisasi lima semaphore
		pthread_join(tid[i],NULL);		//Proses penggabungan/join
										//Fungsi ini menerima dua parameter, yaitu tid yang merupakan thread yang akan digabungkan dan 
										//NULL yang menandakan bahwa tidak perlu melakukan return value dari thread.
}

void * philosopher(void * num)			//philosopher() function, menjalankan tugas masing-masing filosof dalam mengambil sumpit dan makan.
										//Fungsi ini akan dipanggil oleh setiap thread.
{
	int phil=*(int *)num;		//inisialisasi variabel phil yang diisi dengan nilai dari num yang telah dikonversi menjadi pointer ke tipe data integer

	sem_wait(&room);			//mengurangi nilai semafor room sebanyak satu
	printf("\nPhilosopher %d confirmation on room",phil);		//mengeluarkan output phill
	sem_wait(&chopstick[phil]);			//Kedua fungsi ini digunakan untuk mengurangi nilai semafor chopstick pada indeks phil dan (phil+1)%5
	sem_wait(&chopstick[(phil+1)%5]);	//chopstick merepresentasikan chopstick yang tersedia.

	eat(phil);		//merepresentasikan aktivitas makan yang dilakukan oleh philosopher
	sleep(2);		//untuk menunda eksekusi kode selanjutnya selama 2 detik
	printf("\nPhilosopher %d finished eating",phil);		//mengeluarkan output phill

	sem_post(&chopstick[(phil+1)%5]);	//chopstick yang telah digunakan akan dikembalikan dengan menggunakan fungsi ini
	sem_post(&chopstick[phil]);			
	sem_post(&room);				//digunakan untuk menambah nilai semafor sebanyak satu.
}

void eat(int phil)						//eat() function, menampilkan pesan bahwa seorang filosof sedang makan.
{
	printf("\nPhilosopher %d is eating",phil);
}