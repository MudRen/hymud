 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "����"); 
        set("long", @LONG 
���L�����һ���Ϊ������ͥԺ��ͥԺ��Χ���Ż�Ҳ����ֵĲ�ͬ��������һ�� 
��ߵ�̨��֮�ϡ������Χ�и�̨���ƣ����Եý�����ĸߴ����������g���پ��� 
С��ͥԲ���ģ������ɺ繰�ź��񎧰�ăȽ�ˮ�ӵ��ݺύ֯���׵�ʯ���˴����� 
�䡣 
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"skystreet",
       "south" : __DIR__"yuequedian",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/guard1" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1850); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
}     
