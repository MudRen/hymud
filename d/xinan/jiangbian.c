#include <room.h>
inherit ROOM;


void create()
{
        set("short", "���׽���");
        set("long", @LONG
��վ��һ�����͵�ɽ���ϣ������Ǹ�ɽ�ȣ����ϰ�����ȵ�һ������ӿ
�ر�����ȥ�����ƷǷ����޴������ص���ɽ���У�Խ����խ��ɽ�ȣ�����ɽ��
��һ��һľ���ɿ��������������Ҫ���ȥ�����ˡ�һ��ɽ��С·�ӱ���ͨ����
���򶫱�ɽ�����쿪ȥ��
LONG
        );
        set("exits", ([
		"southeast" : "/d/dali/wuliang/anbian",
                "north"  : __DIR__"shangu1",
        ]));
        set("item_desc", ([
                "down":  "�������Ĳ��ξ�����ý��µĴ�ض�����������\n",
        ]));
        setup();
        set("outdoors","xinan");
}
void init()
{        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( arg == "down"){
              message_vision("$N��Ȼ����һ����Ծ�����������.\n"
                "���ڵĽ�ˮ��ʱ��û��$N��С������\n",me);
             me->die();
             command("rumor "+me->query_name()+"�����׽���������ɱ��
\n");
             return 1;
          }
         else{
              write("����Σ�յĵط��㻹������������Ҫ������ȥ(down)���ˡ�\n");
             return 0;
          }
}
           
