// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_ti(string arg);
int do_an(string arg);
void create()
{
        set("short", "����");
        set("long", @LONG
������һ��ˮ���С����߼�����ʲôҲ������, 
��ģģ�����ĸо����Ա߶��Ǿ���,��ˮ�����̹�,
ʹ��е���ƭ�ĸо�,������(ti)�˵ĸо�!

LONG
        );
        set("exits", ([
                "up" : __DIR__"yuanzi",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_ti", "ti");
        add_action("do_an", "an");
}
int do_ti(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
            if( arg=="wall" ) {
             write(
           "������һ��,�о�����������ʲô����,��������԰���ȥ����!\n");
             this_player()->set_temp("tiwall", 1);
             return 1;
       }
}
int do_an(string arg)
{
        object me;
        object room; 
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
  if( arg=="wall" ) {
        if (me->query_temp("tiwall") ) {
            message("vision", me->name() + "���߼�����ʯ��������ȥ,
�����ˡ����������죬�ھ��׵�խ���ռ���ⴥ����\n",
                    environment(me), ({me}) ); 
 message("vision","��赻���������ȥ��¶��������һ��ͨ������
�ڡ� \n",
                    environment(me), ({me}) );
           if(!( room = find_object(__DIR__"jindi")) )
                  room = load_object(__DIR__"jindi"); 
        if(objectp(room)) 
            { 
  me->move(__DIR__"tongdao1");
message("channel:chat", HBRED"������"+me->query("name")+"�ɹ����������!\n"NOR,users());
}
                            this_player()->delete_temp("tiwall");
            return 1;
        }
}
        else {
            write("���밴ʲô����?!\n");
     return 1;
        }
}


