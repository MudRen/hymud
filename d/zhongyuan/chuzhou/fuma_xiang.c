// ���������� /d/city/chuzhou/fuma_xiang.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
�����������б�����¥������һ��С�Ϊʲô��õ����������������
�ӿɿ��ˣ��������ǰ�����������ס��һ������ɡ���������ֵ����������
�����Ե÷ǳ��ľ������ٿ������˳��롣С���Զ���ס�ң�·�������Ƚϴ��լ
Ժ��
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "yangzhou");
    set("exits", ([
        "west"      : __DIR__"zhaiyuan",
        "south"     : __DIR__"xishi",
    ]));
    set("item_desc",    ([
        "west"      : "����լԺ�ĺ�����������ţ�����������������\n",
    ]));        
    set("objects", ([
    ]));
    setup();
}
        
