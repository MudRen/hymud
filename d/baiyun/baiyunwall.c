 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���Ƴ�"); 
        set("long", @LONG 
ԶԶ��ȥ����ǽ�������������һ����ˮ�������Ƴǣ�ȽȽ���С���ԫ֮�ϣ� 
����¥ͤ������֮�����Ʋ�����׭�����������֣� 
                    ��        ��         �� 
LONG 
           ); 
        set("exits",  
           ([  
       "out" : __DIR__"hillroad2",
       "south" : __DIR__"skystreet",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/guard5" : 1,
       __DIR__"npc/guard4" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1745); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
} 
