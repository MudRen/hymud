 inherit ROOM;
void create()
{
        set("short", "��Ȧ");
        set("long", @LONG
Ӫ������ľ��Χ��һ����Ȧ��Ȧ������ʮ��ƥ������Ҳ����һ����ƥƥ��
����ᾣ�������������Ȼ��ȱ�����ϵ�Ե�ʣ��������������̵Ļ�ԭ�ϣ���ǿ��
Ҳ����һ�����׵��е���
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"banditcamp1",
                "west" : __DIR__"banditcamp3",
                        ]));
        set("objects", ([ 
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
