 inherit __DIR__"tutor";
void create()
{
        set_name("ʯ�����", ({ "dagger","��ǽ","wall" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "��ǽ�������š���ͼذ¶ �ҸͶ��𡹰˸����֣�����Χ���ŵĻ��ߣ��ƺ���һ����ʽ��\n");
                set("no_shown", 1);
                set("no_get",1);
                set("teaching", "dagger");
                set("teaching_limit", 400);
        }
        
 }      
