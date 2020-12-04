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
	      set_name("[1;34mº£ÑóÖ®´¥[2;37;0m", ({ "zhanlu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[31mÕ¿Â¬ÍşÁ¦¡¢·æÀû¡¢¼áÓ²¶¼¹Ú¾øµ±ÊÀ£¬ÄËÇ§¹ÅÉñ±ø£¡
[2;37;0mÕâÊÇÒ»¸±ÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÁùÁ½ÈıÇ®µÄ[31mÕ¿Â¬Ö®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[1;31m»ÙÌì[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;33mÃğÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ¾ø´ú:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[1;32mÄ§Íõ[2;37;0m 
°×Ê¯:[1;36mÍêÃÀ[2;37;0m ×ÏÊ¯:[35m±ê×¼[2;37;0m ÖÜÌì:[32m´Ö²Ú[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ÍşÁ¦:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶É¶É[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÇá¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "¶É¶É");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",64);
		set("armor_prop/karey",0);
		set("armor_prop/percao",38);
		set("armor_prop/dexerity",64);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 73);
    set("armor_prop/parry", 53);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 303);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 39);
    set("armor_prop/qi", 59);
    set("armor_prop/jing", 64);
    set("armor_prop/jingli", 64);
    set("armor_prop/damage", 1172);

    set("wtypeA",6);
    set("wtypeB",15);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",16);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",14);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";