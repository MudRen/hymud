#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Ұ����ԭ");
        set("long", @LONG
���ڷ·���һ�����Ҥ��ֻ��һ����ȦΧ��ǽ�����ӣ����������Ҳ�ͣ�ط�
�����ڣ������������߰�������ͷ��ϸ����Ȧ���ƺ������Ĺ켣���д��򣬻���
���»�����ң����಻��ȴ�д������¡���Ȧ���㴦��һ�氼͹��ƽ�Ļ�ǽ����
�һ��м������˸����֣��������ԡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "center" : __DIR__"groundroom",
        ])); 
        set("objects", ([
               __DIR__"obj/daggerbook" : 1,
                        ]));
        set("indoors", "fycycle");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);
        setup();
}        
