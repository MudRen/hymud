 inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
ǰ���Ǹ���壬ʮ�����˼ң��󲿷��ǲ��ݣ���ǰɹ�����������ŷ�ɵ���Ƭ��
�����Ƕ��º�����ȥ�ˣ������Ǵ����ƾɵ�������·��ڴ��˵Ц��ʱ��ʱ̧ͷ����
�������洬����������Ȼ����һƬ��΢΢���Ų��ˡ�������ˮ��ӿ����׵��˻���
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"seaside1",
                "east" : __DIR__"cape",
        ]));
        set("outdoors", "tieflag");
        set("item_desc", ([
         ]));
        set("coor/x",1000);
        set("coor/y",-260);
        set("coor/z",-10);
        setup();
}     
