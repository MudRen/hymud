inherit ROOM;

void create()
{
        set("short", "Ĳ����");
        set("long",@LONG
���Ǹ�ɮ�ǵľ���֮��������ȫ����ľ�Ƴɣ�����ľ����ľ�Ͼ���ȥ
Ƥ����Ȼ���ӣ���һ·������̻Ի͵ĵ��ý�Ȼ��ͬ������������з���
������š���ɮ���⣬����һ�������泯���һ��������
LONG
        );
        set("exits", ([
		"north": __DIR__"banruotai",
"south": __DIR__"six/yaotai",
	]));

//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
