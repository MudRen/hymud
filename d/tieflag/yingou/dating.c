 inherit ROOM;
void create()
{
        set("short", "�����ķ�����");
        set("long", @LONG
һ�ۿ���ȥ������������ǽ�̻Իͣ��ûʸ���������̨���Ǵ����ģ�������
�ط�����ǧ���˰������ӣ�û�˻����ԩ��������������˴��СС�Ķ�����ֻҪ
��˵�����õĶľߣ����ﶼ�С����ң�����һ�顣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"pianting",
  "east" : __DIR__"yingou",
]));
        set("item_desc", ([
                "sign": @TEXT  
���ӵĶķ��� 
�����������ࣾ���������� 
���ࣺ����������������������
������          ��С    ������������    һ��һ
����            �Ĵ�    ��������������  һ��һ
������          ��Χ��  ����������ͬ�㣩һ����ʮ��
��������        �ĵ���                  һ��� 
���ӣ�
��������������
����ʮ����С�� 
TEXT
        ]) ); 
        set("objects", ([
        __DIR__"npc/dice_thrower" : 1,
       __DIR__"npc/obj/stealingbook" : 1,
                        ]) );
        set("NONPC",1);
        set("coor/x",-25);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
} 
void init(){
        object me;
   me = this_player();
        if( me->query("gamble/amount")) {
                me->delete("gamble/amount");
                me->decrease_skill("betting",1);
        }
} 
void reset(){
        object obj;
        ::reset();
        if(!present("stealingbook", this_object())){
                obj = new(__DIR__"npc/obj/stealingbook");
                if(objectp(obj)){
                        obj->move(this_object());
                }
        }
} 
