 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
һ��СС��ľ�ţ����˿��أ����������ڽ�ȥ�����˾��Բ�����ʮ����
���Ǵ�ĦԺ�ĳ��ϣ��ڶ�������ʮ�����ɮ����δ����ȥһ���������ߴ���
û�г������������ź󾿾���ʲô�Ѿ���Ϊ���ֺ�ɮ�������������⡣
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"meiyuan",
  "west" : __DIR__"diyuan",
]));
        set("objects", ([
                __DIR__"npc/owner" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-220);
        set("coor/y",380);
        set("coor/z",70);
        setup();
}
int valid_leave(object me,string dir)
{
        object ob;
        if(userp(me) && dir == "west" && ob=present("xie zhanggui",this_object()))
        {
                if (!me->query_temp("pass_xiezhanggui"))
                {
                        message_vision("$N��$n�����٣������治С�����ȥ��û�Ŷ���\n",ob,me);
                        return notify_fail("");
                }
        }
        return 1;
}        
