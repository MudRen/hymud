 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����ţ����澹Ȼ�Ǽ�������ɵ�ʯ�ң�����������ֵı��ǣ�һ���˱�����
˫�֣�վ�ڸ�ʽ�����ķ�������֮�У�ԲԲ������ͷ���Ѿ���ͺ�����ϴ����ֺ�
������Ц�ݣ������������Ǻ�������мһ�˵�Ц�ݣ������˻���Ϊ�Ǹ�ľ������Ц
���еؿ����㣬�ƺ�������һ������Ʒ�㡣
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"didao1",
       "up" : __DIR__"hetang",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
