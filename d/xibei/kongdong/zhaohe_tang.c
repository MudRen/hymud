//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","�к���");
	set("long",@LONG
�к����������ӭ�Ϳ��˵ĵط�����������Ƕ����ɫ��̫��ͼ��Բ��ʯ����
�ơ�ӭ��ʯ�����������й������ܽ������ʦʥ�񣬶���˫���Σ��ֳ�ն������
˫Ŀ�������������࣬���Է���ʮ�˰������Ӱ������һ������¹�ɺ����
�޻��������߹ٺ�»�������������ȥ������ԯ����
LONG);
	set("exits",
	([
	"west" : __DIR__"zhaitang",
          "south" : __DIR__"tingyuan",
          "north" : __DIR__"xuanyuan_gong",
	]));
	set("need_clean", "�����");
	set("objects", ([
		__DIR__"npc/chen" : 1,
  __DIR__"npc/kdizi1" : 4 ,
		]) );
        setup();
	//place_program(ROOM);
}
