// Room: /d/5lt/tczhongxin.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�������");
	set  ("long",  @LONG
û����������Ǵ����������ġ�ÿ����ĩ���ҽ������ﶼҪ����
Ϊ������ص���ͷ�����ȵĲ��񣬸յ�������˿��ܺܲ�ϰ�ߣ�Ȼ����
���ǳ��������̵ĵط���Խ��Խ����˼����˲����ǵĶ��顣
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"sroad3",
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -140);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}