// Room: /u/cloud/wood.c

inherit ROOM;
int do_cut(string arg);

int i;
void create()
{
        set("short", "��ɽ����");
        set("long",
"��������ɽ���֡������ǲ��������Ũ�ܵ���Ҷ��ס����ա��㷢��������������ڿ���\n"
"һ�����������ﱳ��\n"
);
        set("exits", ([ /* sizeof() == 1 */
            "eastdown" : __DIR__"nroad3",
            ]) );

        set("outdoors", "cloud");

        setup();
}

