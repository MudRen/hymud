 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "��ͷ");
        set("long", @LONG 
���Ƶ����Ϻ�����������������ÿ�µĺ�����ҵ������Ѿ��㹻���Ƶ���������
����ʹ�ã����԰��Ƴ�����Ȼ�����ݻ��������Ƴ����⻹�Ǹ�����ƽ�����Ϻ�������
Ϊ������Ƶ������������Ҫ����᲻ʱ��ǲ��ֻ���˰�������������Ŀ�ĳԺ�����
����Ʒ��������Ҫ������ˣ�Ҳ���Գ˴���Щ�غ��Ĵ����ɡ�
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"baiyundu",
            ])); 
        set("objects", ([
        __DIR__"obj/boat" :1,
        ]));
        set("outdoors", "baiyun"); 
        set("coor/x",18); 
        set("coor/y",-1500); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}      
