

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

int num=4,q,lon;

struct status{
    char name[200];
    int hp;
    int magic;
    int strength;
    int defence;
    int force;
    int action;
    int tired;
    int arm;
    int target;
    int element;
};
typedef struct status sta;
sta player[10],enemy[10];
void print(void);
int main(int argc, const char * argv[]) {
    srandom(/*(unsigned int)time(NULL)*/1625);
    char namae[200],boss[20][200];int number=0,turn[30],play[30],damage,i,j,our,defo,count,Regene;
    count=0;
    FILE *fp;
    printf("セーブデータから開始したい場合は、0と入力してください\n");
    scanf("%d",&defo);
    if(defo==0){
        fp=fopen("save.txt","r");
        fscanf(fp,"%d\n",&num);
        for(i=0;i<num;i++){
            fscanf(fp,"%[^\n]%*c",player[i].name);
            fscanf(fp,"%d\n",&player[i].hp);
            fscanf(fp,"%d\n",&player[i].magic);
            fscanf(fp,"%d\n",&player[i].strength);
            fscanf(fp,"%d\n",&player[i].defence);
            fscanf(fp,"%d\n",&player[i].force);
            fscanf(fp,"%d\n",&player[i].arm);
            fscanf(fp,"%d\n",&player[i].element);
        }
        fscanf(fp,"%d\n",&number);
        for(i=0;i<number;i++){
            fscanf(fp,"%[^\n]%*c",enemy[i].name);
            fscanf(fp,"%d\n",&enemy[i].hp);
            fscanf(fp,"%d\n",&enemy[i].magic);
            fscanf(fp,"%d\n",&enemy[i].strength);
            fscanf(fp,"%d\n",&enemy[i].defence);
            fscanf(fp,"%d\n",&enemy[i].force);
            fscanf(fp,"%d\n",&enemy[i].arm);
            fscanf(fp,"%d\n",&enemy[i].element);
        }
        fclose(fp);
    }
    else{
    fp=fopen("username.txt","r");
    printf("全てデフォルトの設定で行いたいなら、0と入力してください。そうでないなら、0以外の数字を入力してください\n");
    scanf("%d%*c",&defo);
    if(defo!=0){
        printf("仲間は何人欲しいですか？(最大十人まで)\n");
        scanf("%d%*c",&num);
        printf("名前は自分で決めますか？それともデフォルトネームにしますか？デフォルトなら0を自分で決めるなら0以外の数字を入力してください\n");
        scanf("%d%*c",&defo);
    }
    for(i=0;i<num;i++){
        if(defo==0){
            fscanf(fp,"%[^\n]%*c",namae);}
        else{
            printf("%d番目の人の名前は?\n",i);
            scanf("%s",namae);
        }
        strcpy(player[i].name,namae);
        player[i].hp=100+(int)(300*random()/RAND_MAX);
        player[i].magic=10+(int)(300*random()/RAND_MAX);
        player[i].strength=30+(int)(300*random()/RAND_MAX);
        player[i].defence=60+(int)(300*random()/RAND_MAX);
        player[i].force=20+(int)(300*random()/RAND_MAX);
        player[i].arm=(int)(100*random()/RAND_MAX);
        player[i].tired=0;
        player[i].element=1;
    }
    fclose(fp);
  /*      for(i=0;i<num;i++){
            lon+=(int)(strlen(player[i].name));
        }
    */
        lon=(num-1)*4;
    fp=fopen("enemyname.txt","r");
    for(i=0;i<10;i++){
        fscanf(fp,"%[^\n]%*c",boss[i]);
    }
    for(i=0;i<2+(int)(8*random()/RAND_MAX);i++){
        strcpy(enemy[i].name,boss[(int)(10*random()/RAND_MAX)]);
        enemy[i].hp=100+(int)(300*random()/RAND_MAX);
        enemy[i].magic=10+(int)(300*random()/RAND_MAX);
        enemy[i].strength=30+(int)(300*random()/RAND_MAX);
        enemy[i].defence=60+(int)(300*random()/RAND_MAX);
        enemy[i].force=20+(int)(300*random()/RAND_MAX);
        enemy[i].arm=(int)(100*random()/RAND_MAX);
        enemy[i].tired=0;
        enemy[i].element=0;
        number++;
            }
        fclose(fp);}
    count=num+number;
    i=0;
    while(1){
        if(i==0){
        for(i=0;i<number;i++){
            printf("%s ",enemy[i].name);
            if(i+1==number){
                printf("が現れた！\n");sleep(1);
            }}
        }
        for(j=0;j<number;j++){
            if(enemy[j].hp>0){
                break;
            }
            if(j+1==number){
                printf("魔王の群れをやっつけた！\n"); exit(-1);
            }
        }
        for(j=0;j<num;j++){
            if(player[j].hp>0){
                break;
            }
            if(j+1==num){
                printf("全滅してしまった...\n");exit(-1);
            }
        }
        for(i=0;i<=num;i++){
            enemy[i].tired=0;
        }
        printf("セーブしますか？するなら0、しないならそれ以外の数字を入力してください\n>>");
        scanf("%d",&defo);
        if(defo==0){
            fp=fopen("save.txt","w");
            fprintf(fp,"%d\n",num);
            for(i=0;i<num;i++){
                fprintf(fp,"%s\n",player[i].name);
                fprintf(fp,"%d\n",player[i].hp);
                fprintf(fp,"%d\n",player[i].magic);
                fprintf(fp,"%d\n",player[i].strength);
                fprintf(fp,"%d\n",player[i].defence);
                fprintf(fp,"%d\n",player[i].force);
                fprintf(fp,"%d\n",player[i].arm);
                fprintf(fp,"%d\n",player[i].element);
            }
            fprintf(fp,"%d\n",number);
            for(i=0;i<number;i++){
                fprintf(fp,"%s\n",enemy[i].name);
                fprintf(fp,"%d\n",enemy[i].hp);
                fprintf(fp,"%d\n",enemy[i].magic);
                fprintf(fp,"%d\n",enemy[i].strength);
                fprintf(fp,"%d\n",enemy[i].defence);
                fprintf(fp,"%d\n",enemy[i].force);
                fprintf(fp,"%d\n",enemy[i].arm);
                fprintf(fp,"%d\n",enemy[i].element);
            }
            fclose(fp);
            printf("プレイを続行しますか？するなら0、しないならそれ以外の数字を入力してください\n>>");
            scanf("%d",&defo);
            if(defo!=0){
                printf("おぉ、神よ！この者たちにひと時の休息を与え給え!\n");
                printf("お疲れ様でした。このまま電源をお切りください\n");
                exit(-1);
            }
        }
        for(i=0;i<num;i++){
                player[i].tired=0;
            print();
            if(player[i].hp>0){
         printf("%sはどうする?\n",player[i].name);
            printf("1.攻撃 2.防御　3.攻撃魔法 4.回復魔法　5.ライブラ\n>>");
            scanf("%d%*c",&player[i].action);
                if(player[i].action>5||player[i].action==0){
                    printf("入力に失敗しました。もう一度入力してください\n>>");
                    i--;continue;
                }
                if(player[i].action==5&&player[i].magic<30){
                    printf("MPが足りません!\n");
                    i--;continue;
                }
            if ((player[i].action==3||player[i].action==4)&&player[i].magic<5){
                printf("MPが足りません!\n");
                i--;continue;
            }
            if(player[i].action==4){
                printf("誰に？\n");
                for(j=0;j<num;j++){
                    if(player[j].hp>0){
                        printf("%d %s ",j,player[j].name);
                    }
                    if(j+1==num){
                        printf("\n>>");
                    }
                }
                scanf("%d",&player[i].target);
            }
            else if(player[i].arm!=2&&player[i].action!=2){
                printf("誰を? ");
                for(j=0;j<number;j++){
                    if(enemy[j].hp<=0){
                        continue;}
                    else{printf("%d %s ",j,enemy[j].name);}
                    if(j+1==number){
                        printf("\n>>");
                    }
                }
                 scanf("%d",&player[i].target);
            }
        }
    }
        for(i=0;i<count;i++){
            our=(int)((count)*random()/RAND_MAX);
            if(our==count){
                i--;continue;
            }
            if(our>=num &&enemy[our-num].tired==0){our-=num;
                play[i]=our;
                turn[i]=enemy[our].element;
                enemy[our].tired=1;
            }
            else if(our>num &&enemy[our-num].tired==1){
                i-=1;continue;
            }
            else if(our<num&&player[our].tired==0){
                play[i]=our;
                turn[i]=player[our].element;
                player[our].tired=1;
            }
            else {
                i-=1;continue;
            }
        }
        for(i=0;i<count;i++){
           
            switch(turn[i]){
                case 1:
                    if(player[play[i]].hp<=0){
                        continue;
                    }
                    for(j=0;j<number;j++){
                        if(enemy[j].hp>0){
                            break;
                        }
                        if(j+1==number){
                            printf("魔王の群れをやっつけた！\n"); exit(-1);
                        }
                    }
                    
                    if(player[play[i]].action==4){
                        if(player[player[play[i]].target].hp<=0){
                            damage=(int)(10+player[play[i]].defence*random()/RAND_MAX);
                            player[play[i]].hp+=damage;player[play[i]].magic-=5;
                            print();
                            printf("%sは%sを%d回復した\n",player[play[i]].name,player[play[i]].name,damage);sleep(1);
                            continue;
                        }
                        else{
                            damage=(int)(10+player[play[i]].defence*random()/RAND_MAX);
                            player[player[play[i]].target].hp+=damage;player[play[i]].magic-=5;
                            print();
                            printf("%sは%sを%d回復した\n",player[play[i]].name,player[player[play[i]].target].name,damage);sleep(1);
                            continue;
                        }
                    }
                        if(player[play[i]].action==2){
                            print();
                            printf("%sは身を守っている\n",player[play[i]].name);sleep(1);continue;
                        }
                 if(player[play[i]].action==3){
                            if(enemy[player[play[i]].target].hp>0){
                                damage=(int)(10+player[play[i]].force*random()/RAND_MAX-30*random()/RAND_MAX);
                                if(enemy[player[play[i]].target].action==2){
                                    damage*=8/10;
                                }
                                if(damage<0){
                                    damage=0;
                                }
                                enemy[player[play[i]].target].hp-=damage;
                                print();
                                printf("%sはメラを唱えた！%sに%dダメージ与えた\n",player[play[i]].name,enemy[player[play[i]].target].name,damage);sleep(1);
                                if(enemy[player[play[i]].target].hp<=0){
                                    printf("%sを倒した!\n",enemy[player[play[i]].target].name);sleep(1);
                                }
                                continue;
                            }
                            else {
                                while(1){
                                    player[play[i]].target=(int)(number*random()/RAND_MAX);
                                    if(enemy[player[play[i]].target].hp>0){
                                        break;
                                    }
                                }
                                damage=(int)(10+player[play[i]].force*random()/RAND_MAX-30*random()/RAND_MAX);
                                if(enemy[player[play[i]].target].action==2){
                                    damage*=8/10;
                                }
                                if(damage<0){
                                    damage=0;
                                }
                                enemy[player[play[i]].target].hp-=damage;
                                player[play[i]].magic-=5;
                                print();
                                printf("%sはメラを唱えた！%sに%dダメージ与えた\n",player[play[i]].name,enemy[player[play[i]].target].name,damage);sleep(1);
                                if(enemy[player[play[i]].target].hp<=0){
                                    printf("%sを倒した!\n",enemy[player[play[i]].target].name);sleep(1);
                                }
                                continue;
                            }
                        }
                        if(player[play[i]].action==1&&player[play[i]].arm>=98){
                            print();
                            for(j=0;j<number;j++){
                                if(j==0){
                                    printf("%sの攻撃！",player[play[i]].name);
                                }
                                if(enemy[j].hp<=0){
                                    continue;
                                }
                                else{
                                    damage=(int)(10+player[play[i]].strength*random()/RAND_MAX-enemy[j].defence*random()/RAND_MAX);
                                    damage*=(1-j)/10;
                                    if(enemy[j].action==2){
                                        damage*=8/10;
                                    }
                                    enemy[j].hp-=damage;
                                    printf("%sに%dダメージ与えた\n",enemy[j].name,damage);sleep(1);
                                    if(enemy[j].hp<=0){
                                        printf("%sを倒した!\n",enemy[j].name);sleep(1);
                                    }
                                }
                            }
                            
                            continue;
                        }
                     if(player[play[i]].action==1){
                            if(enemy[player[play[i]].target].hp>0){
                            damage=(int)(10+player[play[i]].strength*random()/RAND_MAX-enemy[i].defence*random()/RAND_MAX);
                                if(enemy[player[play[i]].target].action==2){
                                    damage*=8/10;
                                }
                                if(damage<0){
                                    damage=0;
                                }
                            enemy[player[play[i]].target].hp-=damage;
                                print();
                                printf("%sの攻撃！%sに%dダメージ与えた\n",player[play[i]].name,enemy[player[play[i]].target].name,damage);sleep(1);
                                if(enemy[player[play[i]].target].hp<=0){
                                    printf("%sを倒した!\n",enemy[player[play[i]].target].name);sleep(1);
                                }
                                continue;
                            }
                            else {
                                while(1){
                                player[play[i]].target=(int)(number*random()/RAND_MAX);
                                if(enemy[player[play[i]].target].hp>0){
                                    break;
                                }
                            }
                            damage=(int)(10+player[play[i]].strength*random()/RAND_MAX-enemy[i].defence*random()/RAND_MAX);
                            if(enemy[player[play[i]].target].action==2){
                                damage*=8/10;
                            }
                            if(damage<0){
                                damage=0;
                            }
                            enemy[player[play[i]].target].hp-=damage;
                                print();
                            printf("%sの攻撃！%sに%dダメージ与えた\n",player[play[i]].name,enemy[player[play[i]].target].name,damage);sleep(1);
                                if(enemy[player[play[i]].target].hp<=0){
                                    printf("%sを倒した!\n",enemy[player[play[i]].target].name);sleep(1);
                                }
                            continue;
                        }
                        }
                     else if(player[play[i]].action==5){
                         if(enemy[player[play[i]].target].hp>0){
                             damage=(int)(player[play[i]].force*random()/RAND_MAX);
                             if(damage>=80){
                                 print();
                                 printf("%sの残りHPは%dです。\n",enemy[player[play[i]].target].name,enemy[player[play[i]].target].hp);sleep(1);
                             }
                             else{
                                 print();
                                 printf("魔法の壁に弾かれて情報がわからない！\n");sleep(1);
                             }
                             continue;
                         }
                         else {
                             while(1){
                                 player[play[i]].target=(int)(number*random()/RAND_MAX);
                                 if(enemy[player[play[i]].target].hp>0){
                                     break;
                                 }
                             }
                             damage=(int)(player[play[i]].force*random()/RAND_MAX);
                             if(damage>=80){
                                 print();
                                 printf("%sの残りHPは%dです。\n",enemy[player[play[i]].target].name,enemy[player[play[i]].target].hp);sleep(1);
                             }
                             else{
                                 print();
                                 printf("魔法の壁に弾かれて情報がわからない！\n");sleep(1);
                             }
                             continue;
                         }
                     }
                    
                default:
                    if(enemy[play[i]].hp<=0){
                                continue;
                    }
                    for(j=0;j<num;j++){
                        if(player[j].hp>0){
                            break;
                        }
                        if(j+1==num){
                             printf("全滅してしまった...\n");sleep(1);exit(-1);
                        }
                    }
                    Regene=(int)(100*random()/RAND_MAX);
                    if(Regene>95){
                        while(1){
                            enemy[play[i]].target=(int)(number*random()/RAND_MAX);
                            if(enemy[enemy[play[i]].target].hp>0){
                                break;
                            }
                        }
                            damage=(int)(10+enemy[play[i]].defence*random()/RAND_MAX);
                            enemy[enemy[play[i]].target].hp+=damage;
                        print();
                            printf("%sは%sを%d回復した\n",enemy[play[i]].name,enemy[enemy[play[i]].target].name,damage);sleep(1);
                        
                            continue;
                    }
                    
                        if(enemy[play[i]].action==2){
                            print();
                            printf("%sは身を守っている\n",enemy[play[i]].name);sleep(1);
                            continue;
                        }
                        if(enemy[play[i]].action==1&&enemy[play[i]].arm>=98){
                            for(j=0;j<num;j++){
                                if(j==0){
                                    printf("%sの攻撃！",enemy[play[j]].name);sleep(1);
                                }
                                if(player[j].hp<=0){
                                    continue;
                                }
                                else{
                                    damage=(int)(10+enemy[play[i]].strength*random()/RAND_MAX-player[j].defence*random()/RAND_MAX);
                                    damage*=(1-j)/10;
                                    if(player[j].action==2){
                                        damage*=8/10;
                                    }
                                    if(damage<0){
                                        damage=0;
                                    }
                                    player[j].hp-=damage;
                                    print();
                                    printf("%sに%dダメージ与えた\n",player[j].name,damage);sleep(1);
                                    if(player[j].hp<=0){
                                        printf("%sは死んでしまった!\n",player[j].name);sleep(1);
                                    }
                                }
                            }
                            
                            continue;
                        }
                        else if(enemy[play[i]].action==1){
                                while(1){
                                    enemy[play[i]].target=(int)(num*random()/RAND_MAX);
                                    if(player[enemy[play[i]].target].hp>0){
                                        break;
                                    }
                                }
                                damage=(int)(10+enemy[play[i]].strength*random()/RAND_MAX-player[i].defence*random()/RAND_MAX);
                                if(player[enemy[play[i]].target].action==2){
                                    damage*=8/10;
                                }
                            if(damage<0){
                                damage=0;
                            }
                                player[enemy[play[i]].target].hp-=damage;
                            print();
                                printf("%sの攻撃！%sに%dダメージ与えた\n",enemy[play[i]].name,player[enemy[play[i]].target].name,damage);sleep(1);
                            if(player[enemy[play[i]].target].hp<=0){
                                printf("%sは死んでしまった!\n",player[enemy[play[i]].target].name);sleep(1);
                            }
                            continue;
                        }
                            else {
                                while(1){
                                    enemy[play[i]].target=(int)(num*random()/RAND_MAX);
                                    if(player[enemy[play[i]].target].hp>0){
                                        break;
                                    }
                                }
                                damage=(int)(10+enemy[play[i]].force*random()/RAND_MAX-30*random()/RAND_MAX);
                                if(player[enemy[play[i]].target].action==2){
                                    damage*=8/10;
                                }
                                if(damage<0){
                                    damage=0;
                                }
                                player[enemy[play[i]].target].hp-=damage;
                                print();
                                printf("%sの攻撃！%sに%dダメージ与えた\n",enemy[play[i]].name,player[enemy[play[i]].target].name,damage);sleep(1);
                                if(player[enemy[play[i]].target].hp<=0){
                                    printf("%sは死んでしまった!\n",player[enemy[play[i]].target].name);sleep(1);
                                }
                                continue;
                                
            }
                        }
        }
    }
    
return 0;
}
void print(void){
    printf("\x1b[2J");
        
        for(q=0;q<lon;q++){
            printf("ー");
            if(q+1%3==0){
                printf("ー");
            }
        }
        printf("\n");
        printf("|");
        for(q=0;q<num;q++){
            printf("%s ",player[q].name);
        }
    printf("|");
        printf("\n");
    printf("|");
        for(q=0;q<num;q++){
            if(player[q].hp<0){
                printf("HP 0");continue;
            }
            printf(" HP%d ",player[q].hp);
        }
    printf("|");
        printf("\n");
    printf("|");
        for(q=0;q<num;q++){
            if(player[q].magic<100){
                printf(" MP%d  ",player[q].magic);continue;
            }
            printf(" MP%d ",player[q].magic);
        }
    printf("|");
        printf("\n");
        for(q=0;q<lon;q++){
            printf("ー");
            if(q+1%3==0){
                printf("ー");
            }
        }
        printf("\n");
    
}



