 // Room: /d/shaolin/muwu.c
inherit ROOM; 
void create()
{
        set("short", "Сľ��");
        set("long", @LONG
����һ���ª��Сľ�ݣ����ڿ��߷���һ��ľ�崲���м���
һ��ľ�������Ϸ��ű�īֽ��ͼ���ʫ����һ�����˾���һλ��
���ˣ�������һƬ���̵����֡�
LONG
        );
        set("no_clean_up", 0); 
        set("exits",([
        "east" : __DIR__"zhulin/exit",
])); 
        setup();
        replace_program(ROOM);
}  
