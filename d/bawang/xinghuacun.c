 inherit ROOM;
 
void create() 
{ 
        set("short", "�ӻ���Ƽ�"); 
 
        set("long", @LONG 
Զɽǰ����ˮ���Ǽ��ӻ���Ƽң���Ȼֻ�Ǹ�СС�ľ���������Ҳ��СС���� 
�ˡ�СС��ͥԺ����������СС���Ż���СС�����ã���¯���Ƶģ���һ���۾�С 
С������СС�����СС��Ů�ˡ� 
LONG); 
 
        set("exits",([ 
        "east":"/d/wudang/wdroad1",
        ]) ); 
 
        set("indoors", "bawang");
        set("objects", ([ 
                __DIR__"npc/xinghua": 1, 
                __DIR__"npc/xusan": 1, 
        ])); 
        set("coor/x",90);
        set("coor/y",-40);
        set("coor/z",0);
        set("indoors", "bawang"); 
        setup(); 
        replace_program(ROOM); 
}  
