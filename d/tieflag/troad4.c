 // searoad.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
������������������������б��·���ԵĹ�ľ����������ľ��Խ�ߵ���Խ������
������ȥ��ȻҪ�ߵ������ȥ�ˡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"troad2",
  "east" : __DIR__"plain",
]));
        set("outdoors", "tieflag");
        set("coor/x",970);
        set("coor/y",-290);
        set("coor/z",-10);
        set("coor/x",970);
        set("coor/y",-290);
        set("coor/z",-10);
        set("coor/x",970);
        set("coor/y",-290);
        set("coor/z",-10);
        setup();
}  
int valid_leave(object who,string dir)
{
        if(userp(who) && random(3))
        {
                who->move(this_object());
                return notify_fail(""); 
        }
        return 1;
}    
