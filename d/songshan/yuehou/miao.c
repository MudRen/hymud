// /d/yuehou/miao.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������������ഫ�������ɴ��������������˵��ص�
���������˵�ͳ�Σ�����Ϊ�˼�������˽����������������
����겻�ϣ��ܶ��˶�����������ƽ������˵�ǳ����顣
LONG
        );

       set("exits", ([
                "east"             : __DIR__"tupo2",
]) );

       set("light_up", 1);

       setup();
       replace_program(ROOM);
}

