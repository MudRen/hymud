 inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG                 
�ڹ�ľ����һ������������С·������ڡ�С·ʮ�ֹ⻬�����Ǿ��������߶���
�ӹ�ľ�в�ʱ����һֻ���ӣ�������ǰһ�Σ�����ûӰ�ˡ�
LONG
        );
        set("exits", ([ 
           "westup" : __DIR__"troad0",
                   "north" : __DIR__"troad2",
        
         ]));                                  
                set("objects",([
              __DIR__"npc/rabbit" : 1,
        ]));
        set("outdoors","tieflag");      
        set("coor/x",170);
        set("coor/y",-10);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-10);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-10);
        set("coor/z",20);
        setup();
} 
