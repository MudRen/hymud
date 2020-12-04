#include <ansi.h> 
#include <armor.h>

inherit NECK;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[34m�÷�֮����[2;37;0m", ({ "good neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
�÷�֮����[2;37;0m����һ�����ޱȼ�Ӳ��[31m����ʯ[2;37;0m����[1;33mľ�޻�[2;37;0m�Ƴɣ�������������Ǯ��[34m�÷�֮����[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ޱȼ�̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;32mħ��[2;37;0m [36mľ[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [31m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m��ʥ[2;37;0m ��Դ:[36m����[2;37;0m 
����:[32m�ֲ�[2;37;0m 
����:[32m�ֲ�[2;37;0m ����:[36m����[2;37;0m ����:[36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "����");
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",24);
		set("armor_prop/karey",12);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 96);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 37);
    set("armor_prop/qi", 12);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 79);

    set("wtypeA",9);
    set("wtypeB",5);
    set("wtypeC",10);
    set("wtypeD",9);
    set("wtypeE",3);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";