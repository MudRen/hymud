 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���¥"); 
        set("long", @LONG 
���¥�ăɶˣ����O��һ�����ܼ�픵��Iͤ������¥�ϵĹ��Σ����滷�������
ͻ�����ߵ��e�䣬������䁣�������ΰ����"���¥"֮�ơ�¥�Ϲ�׭һ����
                           ��    �� 
                           ��    ��
                           ӭ    ��
                           ��    ��
LONG 
           ); 
        set("exits",  
           ([  
       "northdown" : __DIR__"dragonplace",
       "southeast" : __DIR__"duixiuhill",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/songshi" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",8); 
        set("coor/y",-1690); 
        set("coor/z",11); 
        setup(); 
        replace_program(ROOM); 
}   
