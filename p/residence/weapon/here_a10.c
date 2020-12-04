#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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
	      set_name("[1;31mËé²½[2;37;0m", ({ "qiankun boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
		set("long", @LONG
[1;33m´ËÎï×óÓÒÁ½±ß·Ö±ğÒÔºÚ°×Á½ÖÖÆæÌúÈÜÖı¶ø³É£¬Ò»ºÚÒ»°×£¬ÇĞºÏÇ¬À¤£¬°üº¬ÒõÑôÖ®Æø£¬ºÃÒ»±ú±¦Îï£¡
[2;37;0mÕâÊÇÒ»Ë«ÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¶ş½ïËÄÁ½Ò»Ç®µÄ[1;33mÇ¬À¤Ö®Ñ¥[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[35m±ê×¼[2;37;0m ÉÁµç:[1;36mÍêÃÀ[2;37;0m 
³¤Éú:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÁ½¹û[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÊÖ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "here");
		set("ownername", "Á½¹û");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 52);
    set("armor_prop/attack", 74);


    set("armor_prop/armor", 205);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 34);
    set("armor_prop/jing", 36);
    set("armor_prop/jingli", 36);
    set("armor_prop/damage", 104);

    set("wtypeA",8);
    set("wtypeB",8);
    set("wtypeC",14);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",11);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";