//zhonglou.c

inherit ROOM;

void create()
{
        set("short","�ӹ�¥");
        set("long", @LONG
���Ĺ���Ϊ���������������޵��ӹ�¥����¥�¿����Ŷ���ȥ����
�������ʯ���������Ͼ͵���¥������ͤ��һ����ͭ�����Ĵ�������ڴֵ�
���ӹ���ͤ�ڵĴ���֮�ϡ�������Χ�ú��ĺ��������������ֿ�������.
LONG
        );
        set("exits", ([ 
                "south"         :       __DIR__ "lroad5",    
                "north"         :       __DIR__ "gubei",
                ])
        );
//      replace_program(ROOM);
        setup();
}

