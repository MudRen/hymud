inherit ROOM;

void create()
{
  set ("short", "ũ��");
  set ("long", @LONG

һ�����ũ�ᣬ��ɨ�ĸɸɾ������������������ȵ���λ������
���м�����������ˮ����ǽ�Ƕ��Ÿ��ֹϹ��߲ˣ�����ֱ����ˮ��
LONG);

set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"cunkou",
]));



        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

