 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���"); 
        set("long", @LONG 
�߽����ţ�һ�����ֱ�ֱ��ǰ����û��ͤ��֮�С���ֵă������B��ͨ�����ȏT 
�������빤ֱ�������о�������һ������ׯ�µ�������������ס��������Ц�⡣ 
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"baiyunwall",
       "west" : __DIR__"zhanmangtai",
       "east" : __DIR__"ziqilou",
       "south" : __DIR__"fightdoor",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1800); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
}   
