//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","������");
	set("long",@LONG
�����ʯ���࣬��״���죬���ϴ�ʯ��ͻ����Ѩ���أ�����ʯ�ң�ʯ�ţ�ʯ
����ʯ�ʵȣ���Ϊ�Ϲ�³��������֮������ʿ�����������±ߣ���һ���˶��ģ�
������һ�������̣�������ȥ�������ϻ�������ʯ֮�ż���
LONG);
	set("exits",
	([
          "east" : __DIR__"shanmen",
	"west" : __DIR__"zixiao_ya",
          	]));
          	set("need_clean", "�����");
        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
