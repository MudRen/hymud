// /u/xiaozhen/simiao.c

inherit ROOM;

void create()
{
        set("short", "Ǭʥ������");
        set("long",@LONG
���ķ����Ѿ���Щ�ƾ��ˣ���ǰ�����еķ���ȴͨ����
ҫ�ۣ������������ơ�������һ����¯�����������������Ů��
�׵��㣬�ɼ�Ǭʥ�¹�ģ����ȴ�����ʢ����������Ժ�Ĳ�
LONG
        );

	
        set("exits", ([
                "east" : __DIR__"wroad2",
		  "south" : __DIR__"simiao2",
        ]));
        set("objects",([
                __DIR__"obj/xianglu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
