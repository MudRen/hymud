// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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

void create()
{
	set_name("[1;31mÊ¥Ä¸Ö®Ø°Ê×[2;37;0m", ({ "general dagger", "dagger" }));
	set_weight(10595);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
Ê¥Ä¸Ö®Ø°Ê×[2;37;0mÕâÊÇÒ»°ÑÓÉÊ®·Ö¼áÓ²µÄ[33mÉúÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Ò»½ïÒ»Á½¾ÅÇ®µÄ[1;31mÊ¥Ä¸Ö®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´Ê®·Ö·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[32m´Ö²Ú[2;37;0m 
[40mµØ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[31m¾«ÖÂ[2;37;0m ÌìÁé:[33mÒ»°ã[2;37;0m ¾ø´ú:[32m¼«²î[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
ÌåÁé:[33mÒ»°ã[2;37;0m ÉÁµç:[33mÒ»°ã[2;37;0m 
ÖÜÌì:[32m¼«²î[2;37;0m ²»ÀÏ:[33mÒ»°ã[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",9);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",2);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 10);
    set("weapon_prop/armor", 4);
    set("weapon_prop/defense", 7);
    
    set("weapon_prop/neili", 2);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 7);
    set("weapon_prop/jingli", 7);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",8);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",3);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 6);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_dagger(459);
	setup();
}



#include "/obj/ritem/weaponzy.h";