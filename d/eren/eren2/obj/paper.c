 inherit ITEM;
void create()
{
        set_name("���Ƶ���Ƥֽ", ({"paper", "ֽ"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���Ѿ������˵���Ƥֽ��������ּ���ȱ��ȫ������Լ�ɱ��ĸ��֡�
        �ر�                   
                       ����
\n");
                set("value", 1);
        }
}       
