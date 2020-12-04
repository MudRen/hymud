#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "С����Ĺ�����");
    set("long", "�õط���\n");

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc1" : 1,
  __DIR__"npc2" : 1,
  //__DIR__"tang2" : 1,
  __DIR__"long/long" : 1,
  //__DIR__"gboxt2" : 50,
  //"/adm/fubendoor" : 1,
  //"clone/misc/maze_doort" : 1,
  //"clone/box/gbox" : 50,
]));
//        set("objects", ([
//                "/clone/master/master"+random(24)+1 : 1,
//	]));

  set("exits", ([ /* sizeof() == 1 */

//"test" : "/p/migong/boss/vrm16/maze/entry",
"in" : "/u/hxsd/migong",
  "down" : "/u/hxsd/neishi",
 	
]));
//    set("objects",  ([
//    ]));
set("pingan",1);
  set("valid_startroom", 1);
  set("outdoors", "/u/lywin");

  setup();
}
void init()
{
        mixed *local;
        int  t;
string a="anpc"+random(17);
string b="anpc"+random(17);
string c="anpc"+random(17);
string d="anpc"+random(17);

        local = localtime(time()*60);
        t = local[2] * 60 + local[1];       
        add_action("do_look", "look");
                add_action("do_enter", "south");
}

/*
30-260        ��ҹ
260-510       ����
510-630       �糿
630-810       ����
810-990       ����
990-1170      ����
1170-1360     ����
1360-�ڶ���30 ҹ��
*/


int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                set("exits/down", "/d/gaibang/inhole");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
int do_look()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];
      
        if( t > 30 && t < 260)
        {
                set("long", BLU"�Ƿ�����ת������Ǩ�ƣ�����ǰ����һ˿�ڰ���������Ҫ������С
�����˯�����ѵĴ��ϣ������õ�������Ѱ�Լ����е���Ů��\n");
        }
        if( t > 260 && t < 510)
        {
                set("long", HIC"���΢�������ݴ�¶������������С����Ĺ�������һƬ���ã����峿
�������������͸�С�������޵�ϣ����\n"NOR);
        }
        if( t > 510 && t < 630)
        {
                set("long", HIY"�������ϰ�����һ����ÿ�õĿ�ʼ�� ���͵�С��������������ˣ���Ϊ
��Ϊ�������Լ�,����Ҫȥ�ϰ��ˡ��ϰ�ȥ�!!\n"NOR);
        }
        if( t < 810 && t > 630)
        {
                set("long", HIW"����ĵ�����С���ﲻ�ò�ͣ�������ϵĳ���,�����ﹾ���ҽ�,ʵ����
����ס��,��!�Է�ȥ,���극��С�����ͼ������Ѵ�����ƹ����\n"NOR);
        }
        if( t < 990 && t > 810)
        {
                set("long", HIG"ת�۾͵���Ҫ������ʱ��һ�����͵Ĺ������ڽ�����,���ڻص��ҵ�
С����ͼ���Χ����һ��߿�����Ƭ�߳���,�����������޺á�\n"NOR);
        }
        if( t < 1170 && t > 990)
        {
                set("long", HIR"����С�������ƾ���ڵ�λ������,����С���ﲻ�ò���һ����Сʱ��
����,ȥ��������,����,�ɹ�ȴ.......���ڵ��Ϻ�����һ�����ȭ��̨,��
��������Ҿ����һ����㡣��!\n"NOR);
        }
        if( t < 1360 && t > 1170)
        {
                set("long", RED"��ɫ�Ѿ��ܰ��ˣ������ʱ��С�������ڵ��˽�ͨ��ѧ,������������
��һ��,̸��˵��.��˵��Ϊ.�������Ӣ��͸�����Ҫ�����ˡ�\n"NOR);
        }
        if( t < 30 || t > 1360)
        {
                set("long", BLU"ҹ���˾��ˣ�С�������ſ�Ҫ���µ����ӻص��˼�,���˼��Ѿ�������,��
����һ��,��˯��ǰ���ڴ��Ͽ�����С˵��С������õ���Ϣ��\n"NOR);
        }
}
