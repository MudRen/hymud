#include <room.h>
inherit ROOM;
void cloth_path();
void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
��ʯ��֮�£������ڵص�ȴ������أ�һ����������þ���һ����ȥ��ֻ����
���澫�ɣ��������������ﰴ�硢ѩ���ס��硢��ˮ���ꡢ�������˼䷿�ݣ�����
���뻹��һ������ȥ��ʯ�塣������Ȼ�������˹����˹���Ȼ���ɣ����칤֮���ȴ
������
LONG
        );
        set("objects", ([
       ]));
       
        set("exits/water",__DIR__"swordroom");
        set("exits/snow",__DIR__"bladeroom");
        set("exits/rain",__DIR__"staffroom");
        set("exits/lightning",__DIR__"axeroom");
        set("exits/wind",__DIR__"whiproom");
        set("exits/thunder",__DIR__"hammerroom");
        set("exits/ice",__DIR__"spearroom");
        set("exits/fire",__DIR__"daggerroom");
        set("exits/up",__DIR__"studyroom");
        set("item_desc", ([
                "ʯ��": "���ʯ���ƺ���������(pull)��\n",
                "shiban": "���ʯ���ƺ���������(pull)��\n", 
        ]));
        set("indoors", "fycycle");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);
        setup(); 
}                                    
void init()
{
        add_action("do_open", "pull");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "shiban" || arg == "ʯ��")
        {
        me = this_player();
        message_vision("$N������ȥ��ʯ�壬������������һ��ʯ�ҡ�\n", me);
        if( !query("exits/star") ) {
        set("exits/star", __DIR__"throwingroom");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/star") ) return;
        message("vision",
"ʯ���ֵ��˻�������ס�˼з졣\n",
                this_object() );
                delete("exits/star");
} 