#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;33m����[2;37;0m", ({ "haoqi hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;32m��غ���֮�����ɨħ������Ϊ��Ϊ����֮���ߣ�
[2;37;0m����һ���ɼ����Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[1;32m����֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �����������̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;33m��[2;37;0m:[1;31m��˫[2;37;0m [32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [33m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[34mϸ��[2;37;0m 
����:[1;36m����[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����С[2;37;0m ������һЩ�� [1;32m�޷�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "����С");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 134);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 42);
    set("armor_prop/jing", 29);
    set("armor_prop/jingli", 29);
    set("armor_prop/damage", 775);

    set("wtypeA",12);
    set("wtypeB",0);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",13);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";