 inherit ROOM;
void create()
{
        set("short", "佻���");
        set("long", @LONG
佻��õ��������ǰ����ˣ�����ǽ�Ϸ�ɵĻ���ɢ�������˵����������õ�
���뻹�ǵ����Ǹ���ɫ�������ͭ�ɺף���������Ʈ���������̣�������Ƣ������
���ұ���һ��СС�Ĺ�̨��̨�ӵĺ�����һ��ľ�ܣ������Ϲ����˰�ë��
LONG
        );
        set("exits", ([
                "west" : __DIR__"nwind3",
                "east" : __DIR__"hfenglang1",
        ]));
        set("objects", ([
                __DIR__"npc/showerboy": 1,
        ]) );
        set("coor/x",11);
        set("coor/y",30);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
